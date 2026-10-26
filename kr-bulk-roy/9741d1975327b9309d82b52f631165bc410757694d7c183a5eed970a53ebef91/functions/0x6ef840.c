
void FUN_006ef840(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int *param_4,
                 byte param_5,int param_6)

{
  int *piVar1;
  byte *pbVar2;
  uint uVar3;
  
  do {
    if (param_6 == 0) {
      *param_2 = param_3;
      param_2[1] = param_4;
      return;
    }
    if (param_4 == (int *)0x0) {
LAB_006ef88c:
      uVar3 = (uint)param_3 >> 8;
      param_3 = CONCAT31((int3)uVar3,1);
    }
    else {
      if ((*(int *)param_4[9] == 0) || (piVar1 = (int *)param_4[0xd], *piVar1 < 1)) {
        uVar3 = (**(code **)(*param_4 + 0xc))(param_5);
      }
      else {
        *piVar1 = *piVar1 + -1;
        pbVar2 = *(byte **)param_4[9];
        *(byte **)param_4[9] = pbVar2 + 1;
        *pbVar2 = param_5;
        uVar3 = (uint)param_5;
      }
      if (uVar3 == 0xffffffff) goto LAB_006ef88c;
    }
    param_6 = param_6 + -1;
  } while( true );
}

