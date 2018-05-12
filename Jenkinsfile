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
        sh 'cd build && make test > test.log'
        junit 'build/test.log'
      }
    }
  }
}
