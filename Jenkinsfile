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
                sh """
                    rm -rf build
                    mkdir build
                    cd build
                    cmake -G "Unix Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -DTEST=true ..
                    cmake --build .
                """
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
