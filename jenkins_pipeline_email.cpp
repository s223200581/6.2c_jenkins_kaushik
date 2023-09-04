pipeline{
    agent any
    environment{
        DIRECTORYPATH =  "DIRECTORY_PATH"
        TESTINGENVIRONMENT = "TESTING_ENVIRONMENT"
        PRODUCTIONENVIRONMENT = "Kaushik"
    }
    stages{
        stage('Build'){
            steps{
                echo "fetch the source code from the ${DIRECTORYPATH}"
                echo "compile the code and generate any necessary artifacts"
            }
                post{
                    success{
                        mail to: "ceemalakaushik22@gmail.com"
                        subject: "build status email"
                        body: "john was successful!!!"
                    }
                }
        }
        stage('Test'){
            steps{
            echo "unit tests"
            echo "integration test"
            }
        }
        stage('code'){
            steps{
                echo "check the quality of the code"
            }
        }
        stage('Deploy'){
            steps{
                echo "deploy the application to a ${TESTINGENVIRONMENT}"
            }
        }
        stage('Approval'){
           steps{
            sleep time: 10, unit: "SECONDS"
           }
        }
            stage ('Deploy to Production'){
                steps{
                    echo "DEPLOY the code to ${PRODUCTIONENVIRONMENT}"
                }
            }
        }
    }
