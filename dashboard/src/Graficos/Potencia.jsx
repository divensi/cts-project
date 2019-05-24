

import { Line } from 'react-chartjs-2'
import React from 'react'
import Card from '../Card';

const Potencia = ({dados}) => {
  const labels = dados.map(x => new Date(x.datahora).toLocaleTimeString())
  
  const potencia = dados.map(x => ({
    y: x.potencia,
    t: x.datahora
  }))

  return (
    <Card title="Potência (Watt)">
      <Line
        data={{
          datasets:[
            {
              label: "Potência",
              data: potencia,
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

export default Potencia
