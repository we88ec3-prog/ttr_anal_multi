
uint FUN_006f9de0(uint param_1)

{
  double dVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint local_14;
  uint local_10;
  int iStack_c;
  
  local_14 = param_1;
  uVar2 = param_1 + 1;
  do {
    uVar6 = uVar2;
    if (uVar6 - 1 < *(uint *)(in_EAX + 0x1c)) {
      puVar4 = (undefined4 *)(*(int *)(in_EAX + 0xc) + -0x10 + uVar6 * 0x10);
    }
    else {
      dVar1 = (double)(int)uVar6;
      if (dVar1 == 0.0) {
        puVar4 = *(undefined4 **)(in_EAX + 0x10);
      }
      else {
        iStack_c = (int)((ulonglong)dVar1 >> 0x20);
        local_10 = SUB84(dVar1,0);
        uVar2 = iStack_c + local_10;
        local_10 = (1 << (*(byte *)(in_EAX + 7) & 0x1f)) - 1U | 1;
        puVar4 = (undefined4 *)((uVar2 % local_10) * 0x20 + *(int *)(in_EAX + 0x10));
      }
      for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)puVar4[7]) {
        if ((puVar4[6] == 3) && (dVar1 == *(double *)(puVar4 + 4))) goto LAB_006f9e77;
      }
      puVar4 = &DAT_00c0bfc8;
    }
LAB_006f9e77:
    if (puVar4[2] == 0) {
      uVar5 = uVar6 - local_14;
      uVar2 = local_14;
      while (1 < uVar5) {
        local_14 = uVar2 + uVar6 >> 1;
        iVar3 = FUN_006f9b70(local_14);
        if (*(int *)(iVar3 + 8) == 0) {
          uVar6 = local_14;
          local_14 = uVar2;
        }
        uVar2 = local_14;
        uVar5 = uVar6 - local_14;
      }
      return uVar2;
    }
    uVar2 = uVar6 * 2;
    local_14 = uVar6;
    if (0x7ffffffd < uVar6 * 2) {
      iVar7 = 1;
      iVar3 = FUN_006f9b70(1);
      for (iVar3 = *(int *)(iVar3 + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
        iVar7 = iVar7 + 1;
        iVar3 = FUN_006f9b70(iVar7);
      }
      return iVar7 - 1;
    }
  } while( true );
}

