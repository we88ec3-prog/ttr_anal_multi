
void FUN_0064fa20(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  float local_44;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  uint *local_c;
  int local_8;
  
  FUN_00744640(param_1,param_2);
  if ((*(int *)(in_ECX + 0x24) != 0) && (cVar1 = FUN_0064e8a0(), cVar1 != '\0')) {
    if (*(int *)(in_ECX + 0xa8) == 0) {
      iVar2 = FUN_0040f060();
      uVar4 = (uint)*(ushort *)(*(int *)(iVar2 + 4) + 0x3b);
      FUN_00489d30(uVar4);
      uVar3 = FUN_0053e690(uVar4);
      *(undefined4 *)(in_ECX + 0xa8) = uVar3;
    }
    iVar2 = *(int *)(in_ECX + 0xa8);
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x48) == 0) {
        FUN_0053e120();
      }
      *(int *)(iVar2 + 0x48) = *(int *)(iVar2 + 0x48) + 1;
    }
    if ((*(int *)(in_ECX + 0xa8) != 0) && (*(int *)(*(int *)(in_ECX + 0xa8) + 0x40) != 0)) {
      FUN_0064fc40(in_ECX,param_1,param_2);
      puVar6 = (uint *)(in_ECX + 0x3cc);
      piVar5 = (int *)(in_ECX + 0x114);
      local_14 = 7;
      do {
        local_8 = 5;
        local_10 = piVar5;
        local_c = puVar6;
        do {
          uVar4 = puVar6[-0x23];
          if (((uVar4 != 0xffffffff) && (uVar4 < 4)) &&
             (iVar2 = *(int *)(in_ECX + 0xdc + uVar4 * 8), iVar2 != 0)) {
            local_20 = 0x3f800000;
            local_1c = 0x3f800000;
            local_18 = 0x3f800000;
            local_2c = (float)(piVar5[-1] + param_1);
            local_28 = (float)(*piVar5 + param_2);
            local_24 = 0;
            FUN_00751f90(iVar2,&local_2c,&local_20);
          }
          uVar4 = *puVar6;
          if (((uVar4 != 0xffffffff) && (uVar4 < 4)) &&
             (iVar2 = *(int *)(in_ECX + 0xbc + uVar4 * 8), iVar2 != 0)) {
            local_38 = 0x3f800000;
            local_34 = 0x3f800000;
            local_30 = 0x3f800000;
            local_44 = (float)(piVar5[-1] + param_1);
            local_40 = (float)(*piVar5 + param_2);
            local_3c = 0;
            FUN_00751f90(iVar2,&local_44,&local_38);
          }
          puVar6 = puVar6 + 7;
          piVar5 = piVar5 + 0x1c;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        puVar6 = local_c + 1;
        piVar5 = local_10 + 4;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
      local_10 = piVar5;
      local_c = puVar6;
      FUN_0064ff40(*(int *)(in_ECX + 0x100) + param_1,*(int *)(in_ECX + 0x104) + param_2);
    }
    iVar2 = *(int *)(in_ECX + 0xa8);
    if (iVar2 != 0) {
      piVar5 = (int *)(iVar2 + 0x48);
      *piVar5 = *piVar5 + -1;
      if (*piVar5 == 0) {
        FUN_0053e1d0();
      }
      if (*(int *)(iVar2 + 0x48) < 0) {
        FUN_006edb60("Stage::Release(): refCount < 0");
      }
    }
  }
  return;
}

