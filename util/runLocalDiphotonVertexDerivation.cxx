#include "xAODRootAccess/Init.h"
#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/ScanDir.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "EventLoop/Job.h"
#include "EventLoop/DirectDriver.h"
#include "SampleHandler/DiskListLocal.h"
#include <TSystem.h>


#include "DiphotonVertexDerivation/DiphotonVertexDerivation.h"

#include <EventLoopAlgs/NTupleSvc.h>
#include <EventLoop/OutputStream.h>

int main( int argc, char* argv[] )
{

    // Take the submit directory from the input if provided:
    std::string submitDir = "submitDir";
    if( argc > 1 ) submitDir = argv[ 1 ];

    // Set up the job for xAOD access:
    xAOD::Init().ignore();

    // Construct the samples to run on:
    SH::SampleHandler sh;

    // use SampleHandler to scan all of the subdirectories of a directory for particular MC single file:
    const char* inputFilePath = gSystem->ExpandPathName ("/tmp/rewang/mc15_13TeV/");
    SH::ScanDir().filePattern("AOD.05568499._000200.pool.root.1").scan(sh,inputFilePath);


    // Set the name of the input TTree. It's always "CollectionTree"
    // for xAOD files.
    sh.setMetaString( "nc_tree", "CollectionTree" );

    // Print what we found:
    sh.print();

    // Create an EventLoop job:
    EL::Job job;
    job.sampleHandler( sh );
    job.options()->setDouble (EL::Job::optMaxEvents, 500);

/*
    // define an output and an ntuple associated to that output
    EL::OutputStream output  ("myOutput");
    job.outputAdd (output);
    EL::NTupleSvc *ntuple = new EL::NTupleSvc ("myOutput");
    job.algsAdd (ntuple);
*/


    // Add our analysis to the job:
    DiphotonVertexDerivation* alg = new DiphotonVertexDerivation();
    job.algsAdd( alg );


    // Run the job using the local/direct driver:
    EL::DirectDriver driver;
    driver.submit( job, submitDir );

    return 0;
}
