

import { Line } from 'react-chartjs-2'
import React from 'react'
import Card from '../Card';

const Corrente = ({dados}) => {
  const labels = dados.map(x => new Date(x.datahora).toLocaleTimeString())
  
  const corrente = dados.map(x => ({
    y: x.corrente,
    t: x.datahora
  }))

  return (
    <Card title="Corrente (Ampere)">
      <Line
        data={{
          datasets:[
            {
              label: "Potência",
              data: corrente,
              borderColor: "#3e95cd",
              fill: false
            },
          ],
          labels: labels
        }}
      />
    </Card>
  )
}

export default Corrente
