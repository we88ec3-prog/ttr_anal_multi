
void FUN_006efa50(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int *param_4,
                 byte *param_5,int param_6)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  uint uVar4;
  
  do {
    if (param_6 == 0) {
      *param_2 = param_3;
      param_2[1] = param_4;
      return;
    }
    if (param_4 == (int *)0x0) {
LAB_006efa9f:
      uVar4 = (uint)param_3 >> 8;
      param_3 = CONCAT31((int3)uVar4,1);
    }
    else {
      bVar1 = *param_5;
      if ((*(int *)param_4[9] == 0) || (piVar2 = (int *)param_4[0xd], *piVar2 < 1)) {
        uVar4 = (**(code **)(*param_4 + 0xc))(bVar1);
      }
      else {
        *piVar2 = *piVar2 + -1;
        pbVar3 = *(byte **)param_4[9];
        *(byte **)param_4[9] = pbVar3 + 1;
        *pbVar3 = bVar1;
        uVar4 = (uint)bVar1;
      }
      if (uVar4 == 0xffffffff) goto LAB_006efa9f;
    }
    param_5 = param_5 + 1;
    param_6 = param_6 + -1;
  } while( true );
}

