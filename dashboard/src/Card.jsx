import React from 'react'


import './Card.css'

const Card = ({title, children}) => {
  return (
    <div className="Card">
      <h1>{title}</h1>
      {children}
    </div>
  )
}

export default Card
