

import { Line } from 'react-chartjs-2'
import React from 'react'
import Card from '../Card';

const Temperatura = ({dados}) => {
  const labels = dados.map(x => new Date(x.datahora).toLocaleTimeString())
  
  const temp1 = dados.map(x => ({
    y: x.temperatura1,
    t: x.datahora
  }))
  const temp2 = dados.map(x => ({
    y: x.temperatura2,
    t: x.datahora
  }))
  const temp3 = dados.map(x => ({
    y: x.temperaturaAC,
    t: x.datahora
  }))

  return (
    <Card title="Temperatura (°C)">
      <Line
        data={{
          datasets:[
            {
              label: "Temperatura Interna",
              data: temp1,
              borderColor: "#3e95cd",
              fill: false
            },
            {
              label: "Temperatura Externa",
              data: temp2,
              borderColor: "#8e5ea2",
              fill: false
            },
            {
              label: "Temperatura AC",
              data: temp3,
              borderColor: "#3cba9f",
              fill: false
            }
          ],
          labels: labels
        }}
      />
    </Card>
  )
}

export default Temperatura
