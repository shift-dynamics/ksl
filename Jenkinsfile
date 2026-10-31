pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        echo 'Building..'
        sh 'rm -rf build && meson setup build --buildtype=debug -Dtests=enabled -Db_coverage=true && meson compile -C build'
      }
    }
    stage('Test') {
      steps {
        echo 'Testing..'
        sh 'meson test -C build'
      }
    }
    stage('Coverage') {
      steps {
        echo 'Performing coverage analysis..'
        sh 'ninja -C build coverage-xml'
      }
      post {
        always {
          cobertura coberturaReportFile: '**/coverage.xml'
        }
      }
    }
  }
}
