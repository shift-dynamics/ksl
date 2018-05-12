pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        echo 'Building..'
        sh 'rm -r build'
        sh 'mkdir -p build'
        sh 'cd build'
        sh 'cmake ..'
        sh 'make'
        sh 'cd ..'
      }
    }
    stage('Test') {
      steps {
        echo 'Testing..'
        sh 'cd build'
        sh 'make test > test.log'
        junit 'test.log'
        sh 'cd ..'
      }
    }
  }
}
