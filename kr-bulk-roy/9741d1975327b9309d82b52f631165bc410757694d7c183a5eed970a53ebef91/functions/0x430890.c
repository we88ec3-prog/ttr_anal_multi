
void FUN_00430890(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int *param_4,
                 short *param_5,int param_6)

{
  int *piVar1;
  short *psVar2;
  uint uVar3;
  short sVar4;
  
  do {
    if (param_6 == 0) {
      *param_2 = param_3;
      param_2[1] = param_4;
      return;
    }
    if (param_4 == (int *)0x0) {
LAB_004308e5:
      uVar3 = (uint)param_3 >> 8;
      param_3 = CONCAT31((int3)uVar3,1);
    }
    else {
      sVar4 = *param_5;
      if ((*(int *)param_4[9] == 0) || (piVar1 = (int *)param_4[0xd], *piVar1 < 1)) {
        sVar4 = (**(code **)(*param_4 + 0xc))(sVar4);
      }
      else {
        *piVar1 = *piVar1 + -1;
        psVar2 = *(short **)param_4[9];
        *(short **)param_4[9] = psVar2 + 1;
        *psVar2 = sVar4;
      }
      if (sVar4 == -1) goto LAB_004308e5;
    }
    param_5 = param_5 + 1;
    param_6 = param_6 + -1;
  } while( true );
}

