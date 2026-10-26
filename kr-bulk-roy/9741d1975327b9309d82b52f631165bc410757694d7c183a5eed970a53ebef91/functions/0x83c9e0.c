
undefined4
FUN_0083c9e0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int *param_4,int param_5,
            double param_6)

{
  int iVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined4 *puVar6;
  double dStack_a4;
  float fStack_9c;
  undefined4 uStack_94;
  undefined4 local_90 [13];
  int iStack_5c;
  int *piStack_58;
  double dStack_54;
  int iStack_4c;
  int *piStack_44;
  int *piStack_40;
  int *piStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00906e1b;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_008392d0(DAT_00d61f20 ^ (uint)&stack0xffffff50);
  local_c = 0;
  iVar3 = (**(code **)(*param_4 + 4))();
  if (*(int *)(iVar3 + 4) == -0x5ece0000) {
    iVar3 = (**(code **)(*in_ECX + 0xf0))(param_4);
  }
  else {
    iVar3 = (**(code **)(*param_4 + 4))();
    if (*(int *)(iVar3 + 4) == -0x5ecc0000) {
      iVar3 = (**(code **)(*in_ECX + 0xec))(param_4);
    }
    else {
      iVar3 = 0;
    }
  }
  dStack_a4 = 0.0;
  dVar2 = param_6;
  if ((param_6 == 0.0) && ((iVar3 == 2 || (dVar2 = dStack_a4, iVar3 == 1)))) {
    fStack_9c = (float)param_2[0xb];
    dVar2 = -((double)(float)in_ECX[0x2e] * (double)fStack_9c +
              (double)(float)in_ECX[0x28] * (double)(float)param_2[9] +
              (double)(float)in_ECX[0x2b] * (double)(float)param_2[10] + (double)(float)in_ECX[0x31]
             );
  }
  dStack_a4 = dVar2;
  iVar1 = in_ECX[0x119];
  iVar4 = FUN_0083f5f0(iVar1,*(undefined4 *)(iVar1 + 4),param_3);
  if (in_ECX[0x11a] != 0x9249248) {
    in_ECX[0x11a] = in_ECX[0x11a] + 1;
    *(int *)(iVar1 + 4) = iVar4;
    **(int **)(iVar4 + 4) = iVar4;
    uStack_94 = param_1;
    iVar1 = *(int *)(in_ECX[0x119] + 4);
    puVar6 = local_90;
    for (iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *param_2;
      param_2 = param_2 + 1;
      puVar6 = puVar6 + 1;
    }
    dStack_54 = dStack_a4;
    iStack_5c = iVar1 + 8;
    piStack_40 = *(int **)(param_5 + 0x18);
    piStack_58 = param_4;
    iStack_4c = iVar3;
    if (piStack_40 != (int *)0x0) {
      (**(code **)(*piStack_40 + 4))(piStack_40);
    }
    piStack_44 = *(int **)(param_5 + 0x14);
    if (piStack_44 != (int *)0x0) {
      (**(code **)(*piStack_44 + 4))(piStack_44);
    }
    piStack_3c = *(int **)(param_5 + 0x1c);
    if (piStack_3c != (int *)0x0) {
      (**(code **)(*piStack_3c + 4))(piStack_3c);
    }
    uStack_34 = *(undefined4 *)(param_5 + 0xc);
    uStack_30 = *(undefined4 *)(param_5 + 8);
    uStack_2c = *(undefined4 *)(param_5 + 0x20);
    uStack_38 = *(undefined4 *)(param_5 + 0x10);
    if (iVar3 == 1) {
      FUN_00841880(&uStack_94);
      FUN_00841060(in_ECX + 0xf4);
    }
    else if (iVar3 == 2) {
      FUN_00841880(&uStack_94);
      FUN_008410e0(in_ECX + 0xf8);
    }
    else if (iVar3 == 3) {
      uVar5 = FUN_00841880(&uStack_94);
      FUN_00840fc0(in_ECX + 0xf0,&dStack_a4,uVar5);
    }
    else {
      FUN_0083ec20();
    }
    puStack_10 = (undefined1 *)0xffffffff;
    FUN_00839400();
    ExceptionList = pvStack_18;
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

