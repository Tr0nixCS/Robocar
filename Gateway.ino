

// GatState
#define Stdby 0
#define Processing 1
#define awaitCommand 2
#define awaitParameter 3
#define awaitValue 4
#define awaitEnd 5

char Command, Parameter;
int GatState = Stdby;

void GatewayStatemachine() {
  int x;
  if ((x = Serial.read ()) == -1) return;
  switch (GatState) {
    case Stdby:
      if (x == ':') GatState = awaitCommand;
      break;
    case awaitCommand:
      if (x == 'M' || x == 'S')
      {
        GatState = awaitParameter;
        Command = x;
      }
      else if (x == '@')
      {
        GatState = awaitEnd;
        Command = x;
      }
      else
      {
        GatState = Stdby;
      }
      break;
    case awaitParameter:
      if (x == 'F' || x == 'B' || x == 'S' || x == 'L' || x == 'R' || x == 'l' || x == 'r' || x == 's' || x == 'f' || x == 'b' || x == 'm')
      {
        GatState = awaitEnd;
        Parameter = x;
      }
      else
      {
        GatState = Stdby;
      }
      break;
    case awaitEnd:
      if (x == '\r')
      {
        GatState = Stdby;
        ProcesPacket();
      }
      break;
  }
}

void ProcesPacket(void)
{

  if (Command == '@')
  {
    Serial.print('@');
  }
  if (Command == 'M')
  {
    switch (Parameter) {
      case 'F':
        Forwards();
        break;               
      case 'B':
        Backwards();
        break;
      case 'S':
        Stop();
        break;
      case 'L':
        Left();
        break;
      case 'R':
        Right();
        break;
      case 'l':
        RotLeft();
        break;
      case 'r':
        RotRight();
        break;
    }
  }
  if (Command == 'S')
  {
    switch (Parameter) {
      case 's':
        SysState = 0;
        break;
      case 'f':
        SysState = 1;
        break;
      case 'b':
        SysState = 2;
        break;
      case 'm':
        SysState = 3;
        break;
    }
  }
}
