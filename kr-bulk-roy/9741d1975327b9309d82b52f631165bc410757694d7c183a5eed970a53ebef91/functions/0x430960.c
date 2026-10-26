
void FUN_00430960(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int *param_4,
                 undefined4 param_5,int param_6)

{
  int *piVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  
  do {
    if (param_6 == 0) {
      *param_2 = param_3;
      param_2[1] = param_4;
      return;
    }
    if (param_4 == (int *)0x0) {
LAB_004309b2:
      uVar3 = (uint)param_3 >> 8;
      param_3 = CONCAT31((int3)uVar3,1);
    }
    else {
      if ((*(int *)param_4[9] == 0) || (piVar1 = (int *)param_4[0xd], *piVar1 < 1)) {
        uVar4 = (**(code **)(*param_4 + 0xc))(param_5);
      }
      else {
        *piVar1 = *piVar1 + -1;
        puVar2 = *(undefined2 **)param_4[9];
        *(undefined2 **)param_4[9] = puVar2 + 1;
        *puVar2 = (short)param_5;
        uVar4 = param_5;
      }
      if ((short)uVar4 == -1) goto LAB_004309b2;
    }
    param_6 = param_6 + -1;
  } while( true );
}

