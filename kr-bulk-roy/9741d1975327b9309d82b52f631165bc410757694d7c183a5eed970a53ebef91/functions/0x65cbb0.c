
void FUN_0065cbb0(undefined4 param_1,uint *param_2,int param_3,uint *param_4,int param_5,
                 uint *param_6,int param_7)

{
  undefined4 *in_EAX;
  
  while( true ) {
    if ((param_2 == param_4) && (param_3 == param_5)) break;
    if (param_5 == 0) {
      param_4 = param_4 + -1;
      param_5 = 0x1f;
    }
    else {
      param_5 = param_5 + -1;
    }
    if (param_7 == 0) {
      param_6 = param_6 + -1;
      param_7 = 0x1f;
    }
    else {
      param_7 = param_7 + -1;
    }
    if ((*param_4 & 1 << ((byte)param_5 & 0x1f)) == 0) {
      *param_6 = *param_6 & ~(1 << ((byte)param_7 & 0x1f));
    }
    else {
      *param_6 = *param_6 | 1 << ((byte)param_7 & 0x1f);
    }
  }
  *in_EAX = param_6;
  in_EAX[1] = param_7;
  return;
}

