
void FUN_0042fd20(int param_1,undefined4 *param_2,undefined4 param_3,int *param_4,char *param_5,
                 int param_6)

{
  int *piVar1;
  short *psVar2;
  short sVar3;
  mbstate_t local_14;
  _Cvtvec *local_10;
  undefined4 local_c;
  char local_8 [4];
  
  if (param_6 == 0) {
    *param_2 = param_3;
    param_2[1] = param_4;
    return;
  }
  local_10 = (_Cvtvec *)(param_1 + 8);
  do {
    local_8[0] = *param_5;
    local_c = 0;
    local_14 = 0;
    __Mbrtowc((wchar_t *)&local_c,local_8,1,&local_14,local_10);
    if (param_4 == (int *)0x0) {
LAB_0042fdb1:
      param_3 = CONCAT31(param_3._1_3_,1);
    }
    else {
      sVar3 = (short)local_c;
      if ((*(int *)param_4[9] == 0) || (piVar1 = (int *)param_4[0xd], *piVar1 < 1)) {
        sVar3 = (**(code **)(*param_4 + 0xc))(local_c);
      }
      else {
        *piVar1 = *piVar1 + -1;
        psVar2 = *(short **)param_4[9];
        *(short **)param_4[9] = psVar2 + 1;
        *psVar2 = sVar3;
      }
      if (sVar3 == -1) goto LAB_0042fdb1;
    }
    param_6 = param_6 + -1;
    param_5 = param_5 + 1;
    if (param_6 == 0) {
      *param_2 = param_3;
      param_2[1] = param_4;
      return;
    }
  } while( true );
}

