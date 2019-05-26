import React from 'react'
import Card from '../Card'

import './DadosAtuais.css'

const DadosAtuais = ({dados}) => {
  const dado = dados.length ? dados.slice(-1)[0] : {}

  const tempExterna = dado.temperatura1
  const tempInterna = dado.temperatura2
  const tempAC = dado.temperaturaAC
  const corrente = dado.corrente
  const potencia = dado.potencia

  return (
    <Card title="Dados Atuais">
      <div className="linha">
        <span>Temperatura Externa:</span>
        <h3>{tempExterna} °C</h3>
      </div>
      <div className="linha">
        <span>Temperatura Interna:</span>
        <h3>{tempInterna} °C</h3>
      </div>
      <div className="linha">
        <span>Temperatura Ar Condicionado:</span>
        <h3>{tempAC} °C</h3>
      </div>
      <div className="linha">
        <span>Corrente:</span>
        <h3>{corrente} A</h3>
      </div>
      <div className="linha">
        <span>Potência:</span>
        <h3>{potencia} W</h3>
      </div>
    </Card>
  )
}

export default DadosAtuais