pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        echo 'Building..'
        sh 'rm -r build && mkdir -p build && cd build && cmake .. && make'
      }
    }
    stage('Test') {
      steps {
        echo 'Testing..'
        sh 'make test > test.log'
        junit 'test.log'
      }
    }
  }
}
