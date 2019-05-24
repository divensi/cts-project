import React, { Component } from 'react'

import './App.css';
import Card from './Card';
import Papa from 'papaparse'
import Loading from './Loading';
import Temperatura from './Graficos/Temperatura';
import Potencia from './Graficos/Potencia';
import Corrente from './Graficos/Corrente';


class App extends Component {
  state = {
    dados: null,
    carregando: true
  }

  interval = null

  componentWillMount() {
    this.carregar();

    this.interval = setInterval(this.carregar, 5000)
  }

  carregar = () => {
    
    Papa.parse("/serial.csv", {
      download: true,
      complete: results => {
        //prepara os dados 
        const dados = results.data
          .filter(d => d.length === 6)
          .map(i => ({
            datahora: i[0],
            corrente: i[1],
            potencia: i[2],
            temperatura1: i[3],
            temperatura2: i[4],
            temperaturaAC: i[5]
          }))
        
        this.setState({
          dados: dados,
          carregando: false
        });
      }
    });
  }

  render() {
    if (this.state.carregando) {
      return <Loading />
    }

    return (
      <div className="App">
        <Temperatura dados={this.state.dados} />
        <Potencia dados={this.state.dados} />
        <Corrente dados={this.state.dados} />
      </div>
    )
  }
}

export default App;
