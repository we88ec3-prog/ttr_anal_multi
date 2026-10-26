
undefined4 FUN_0083aa30(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  int unaff_EBX;
  uint uVar5;
  int *piVar6;
  int *piStack_4c;
  int *local_48;
  int iStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  int iStack_38;
  int iStack_34;
  undefined4 uStack_30;
  int *piStack_2c;
  int iStack_28;
  int *piStack_24;
  uint uStack_20;
  int iStack_18;
  undefined4 uStack_14;
  int *piStack_10;
  
  piVar1 = *(int **)(param_1 + 0x3c);
  if (piVar1 != (int *)0x0) {
    local_48 = in_ECX;
    iVar2 = FUN_0083ff20(in_ECX + 0x51,piVar1[0x5b]);
    if ((iVar2 == 0) || (*(int *)(iVar2 + 4) == 0)) {
      iVar2 = (**(code **)(*piVar1 + 4))();
      if (*(int *)(iVar2 + 4) == -0x5ece0000) {
        (**(code **)(*in_ECX + 0x11c))(piVar1);
      }
    }
    else {
      FUN_0085aa60(iVar2,in_ECX);
      (**(code **)(**(int **)(iVar2 + 4) + 0x104))(*(int **)(iVar2 + 4));
      in_ECX = piStack_4c;
    }
    uStack_3c = (**(code **)(*piVar1 + 0x54))();
    uVar5 = 0;
    if (uStack_3c != 0) {
      do {
        iVar2 = (**(code **)(*piVar1 + 0x50))(uVar5,&local_48,&uStack_40,&iStack_44);
        if (iVar2 != 0) {
          (**(code **)(*(int *)in_ECX[0x3b] + 0xe4))((int *)in_ECX[0x3b],local_48,uStack_40);
          piStack_2c = local_48;
          iStack_28 = iStack_44;
          FUN_0083ef60();
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uStack_3c);
    }
    iVar2 = 0;
    do {
      iStack_38 = (**(code **)(*piVar1 + 0x6c))(iVar2);
      local_48 = (int *)0x0;
      if (0 < iStack_38) {
        do {
          piVar6 = local_48;
          iVar3 = (**(code **)(*piVar1 + 100))(local_48,&piStack_4c,&uStack_40,&uStack_3c);
          if (iVar3 != 0) {
            (**(code **)(**(int **)(unaff_EBX + 0xec) + 0x10c))
                      (*(int **)(unaff_EBX + 0xec),iVar2,piStack_4c,uStack_40);
            piStack_24 = piStack_4c;
            uStack_20 = uStack_3c;
            iStack_28 = iVar2;
            FUN_0085df00();
            piVar6 = local_48;
          }
          local_48 = (int *)((int)piVar6 + 1);
        } while ((int)local_48 < iStack_38);
      }
      iStack_34 = (**(code **)(*piVar1 + 0x84))(iVar2);
      iStack_44 = 0;
      if (0 < iStack_34) {
        do {
          iVar3 = iStack_44;
          iVar4 = (**(code **)(*piVar1 + 0x80))(iVar2,iStack_44,&uStack_40,&uStack_30,&piStack_2c);
          if (iVar4 != 0) {
            (**(code **)(*(int *)piStack_4c[0x3b] + 0x114))
                      ((int *)piStack_4c[0x3b],iVar2,uStack_40,uStack_30);
            uStack_14 = uStack_40;
            piStack_10 = piStack_2c;
            iStack_18 = iVar2;
            FUN_0085df00();
            iVar3 = iStack_44;
          }
          iStack_44 = iVar3 + 1;
        } while (iStack_44 < iStack_34);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    return 1;
  }
  return 0;
}

