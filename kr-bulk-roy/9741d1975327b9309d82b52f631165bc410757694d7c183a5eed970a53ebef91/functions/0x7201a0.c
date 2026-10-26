
undefined4 * FUN_007201a0(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  bool bVar8;
  int local_1c;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0xb:
    if (*(int *)(param_1 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
    puVar6 = (undefined4 *)
             FUN_0071ce20(*(int *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0xc),
                          *(undefined4 *)(param_1 + 0x10));
    if (puVar6 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
    FUN_0071d0d0();
    puVar3 = (undefined4 *)FUN_0071f6b0();
    if (puVar3 != (undefined4 *)0x0) {
      uVar4 = *puVar6;
      *(undefined1 *)puVar3 = 0x14;
      *(char *)((int)puVar3 + 1) = (char)uVar4;
      *(undefined2 *)((int)puVar3 + 2) = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = puVar6;
      return puVar3;
    }
    return (undefined4 *)0x0;
  case 0xc:
    FUN_0071d0d0();
    puVar6 = (undefined4 *)FUN_00721210();
    if (*(int *)(param_1 + 0x14) != 0xd) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
    break;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_0071f620();
  case 0xe:
    uVar4 = FUN_0071f6d0(param_1 + 0xc);
    puVar6 = (undefined4 *)FUN_0071bdb0();
    if (puVar6 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f670();
    }
    *puVar6 = 0x312;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = uVar4;
    break;
  case 0xf:
    local_18 = 0;
    cVar2 = FUN_0071c980(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
    if (cVar2 == '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_0071f670();
    }
    puVar3 = (undefined4 *)FUN_0071f6b0();
    puVar6 = (undefined4 *)0x0;
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[1] = 0;
      puVar3[2] = 0;
      *(undefined8 *)(puVar3 + 4) = local_18;
      puVar3[3] = 0;
      *puVar3 = 0x213;
      FUN_0071d0d0();
      return puVar3;
    }
    break;
  case 0x14:
    local_10 = *(undefined4 *)(param_1 + 0xc);
    local_c = *(undefined4 *)(param_1 + 0x10);
    local_18 = 0;
    FUN_0071d0d0();
    local_1c = 0;
    if (*(int *)(param_1 + 0x14) != 0xc) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
    FUN_0071d0d0();
    bVar8 = *(int *)(param_1 + 0x14) != 0xd;
    if (bVar8) {
      uVar4 = FUN_00721210();
      local_18 = CONCAT44(local_18._4_4_,uVar4);
    }
    uVar7 = (uint)bVar8;
    iVar1 = *(int *)(param_1 + 0x14);
    while( true ) {
      if (iVar1 == 0xd) {
        FUN_0071d0d0();
        puVar6 = (undefined4 *)FUN_0071f780(param_1,&local_10,uVar7);
        return puVar6;
      }
      if (iVar1 != 0x15) break;
      FUN_0071d0d0();
      iVar5 = FUN_00721210();
      if (uVar7 < 2) {
        *(int *)((int)&local_18 + uVar7 * 4) = iVar5;
      }
      else {
        *(int *)(local_1c + 0xc) = iVar5;
      }
      iVar1 = *(int *)(param_1 + 0x14);
      uVar7 = uVar7 + 1;
      local_1c = iVar5;
    }
                    /* WARNING: Subroutine does not return */
    FUN_0071f620();
  }
  FUN_0071d0d0();
  return puVar6;
}

