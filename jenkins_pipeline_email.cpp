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
                echo "The code is build usint the built automation tool named John"
                }
            }
        
        stage(' Unit and integration Tests'){
            steps{
            echo "unit tests"
            echo "integration test"
            echo "john used the automation tool"
            }
            post{
                success{
                     mail to: "ceemalakaushik22@gmail.com",
                    subject: "test status email",
                    body: "test is completed"
                }
            }
        }
        stage('code analysis'){
            steps{
                echo "check the quality of the code"
                echo " SonarQube was used as a tool "
            }
        }
        stage('Security scan'){
            steps{
                echo "VeraCode used for security scan"
            }
            post{
                success{
                    mail to: "ceemalakaushik22@gmail.com",
                    subject: "security scan stage ${currentBuild.result}",
                    body: "security scan completed"
                }
            }
        }
        stage('Deploy to staging'){
           steps{
            echo "In Jenkins-deploy the application to a staging server"
           }
        }
        stage ('Integration Tests on staging'){
            steps{
                echo " run the integration tests on the staging environment to ensure the application functions as expected in a production like environment"
            }
        }
        stage ('Deploy to Production'){
                steps{
                    echo "DEPLOY the code to ${PRODUCTIONENVIRONMENT}"
                    echo "Deploy the application to a production server"
                }
            }
        }
    }
