pipeline {
    agent any
    stages {
        stage('submodule update') {
            steps {
                sh 'git submodule init'
                sh 'git submodule update'
            }
        }

        stage('build') {
            steps {
                sh 'bash compile.sh'
            }
        }

        stage('run tests') {
            steps {
                sh 'build/main_tests'
            }
        }

        stage('clean') {
            steps {
                cleanWs()
            }
        }
    }
}
