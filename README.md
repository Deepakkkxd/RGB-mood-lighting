<h1 align="center">🌈 RGB Mood Lighting Control</h1>

<p align="center">
  <strong>Project 3:</strong> Transitioning from simple indicators to <strong>Additive Color Synthesis</strong> using an Arduino, a Joystick, and a KY-016 RGB LED.
</p>

<hr />

<h3>🧠 The Engineering Concept: Additive Color Mixing</h3>
<p>As an EEE student, the RGB LED can be viewed as three independent circuits sharing a single housing. By varying the <strong>Duty Cycle (PWM)</strong> of the Red, Green, and Blue channels, we can create over 16 million colors by mixing light frequencies:</p>



<ul>
  <li>🔴 <strong>Red + Green</strong> = Yellow 🟡</li>
  <li>🔴 <strong>Red + Blue</strong> = Magenta 🟣</li>
  <li>🟢 <strong>Green + Blue</strong> = Cyan 🔵</li>
  <li>⚪ <strong>All Three</strong> = White</li>
</ul>

<hr />

<h3>📦 Hardware & Pin Mapping</h3>
<p>We use the <strong>KY-016 RGB LED Module</strong> and a 2-Axis Joystick. The module features a <strong>Common Cathode (GND)</strong> design.</p>

<table width="100%">
  <thead>
    <tr>
      <th>Component Pin</th>
      <th>Arduino Pin</th>
      <th>Function (Logic)</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>GND (-)</strong></td>
      <td>GND</td>
      <td>Common Ground Rail</td>
    </tr>
    <tr>
      <td><strong>R (Red)</strong></td>
      <td>Pin 9 (~)</td>
      <td>PWM Intensity Control</td>
    </tr>
    <tr>
      <td><strong>G (Green)</strong></td>
      <td>Pin 10 (~)</td>
      <td>PWM Intensity Control</td>
    </tr>
    <tr>
      <td><strong>B (Blue)</strong></td>
      <td>Pin 11 (~)</td>
      <td>PWM Intensity Control</td>
    </tr>
    <tr>
      <td><strong>VRx (Joystick)</strong></td>
      <td>A0</td>
      <td>Analog Input (Red Control)</td>
    </tr>
    <tr>
      <td><strong>VRy (Joystick)</strong></td>
      <td>A1</td>
      <td>Analog Input (Green Control)</td>
    </tr>
    <tr>
      <td><strong>SW (Switch)</strong></td>
      <td>Pin 2</td>
      <td>Digital Input (Blue Toggle)</td>
    </tr>
  </tbody>
</table>



<hr />

<h3>🛠️ Step-by-Step Implementation</h3>
<ol>
  <li><strong>Wiring the LED:</strong> Connect the GND to the Arduino GND. Connect R, G, and B pins to PWM pins 9, 10, and 11.</li>
  <li><strong>Joystick Setup:</strong> Connect VRx and VRy to Analog pins A0 and A1. Connect the SW pin to Digital Pin 2.</li>
  <li><strong>The Logic:</strong> The code <code>maps</code> the 10-bit analog input (0-1023) to an 8-bit PWM output (0-255).</li>
  <li><strong>Interaction:</strong> Moving the stick on the X-axis changes Red; the Y-axis changes Green; clicking the stick toggles Blue.</li>
</ol>



<p align="center"><i>Experimental Note: Using <b>analogWrite()</b> on non-PWM pins will result in simple On/Off behavior rather than smooth color fading!</i></p>
