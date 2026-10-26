
undefined4 FUN_004ebe60(int param_1,uint param_2)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 **ppuVar8;
  undefined4 uVar9;
  int in_ECX;
  undefined4 *puVar10;
  short *psVar11;
  int local_44;
  uint local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  undefined4 local_34;
  int local_30;
  byte local_24;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009249ae;
  local_14 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x5ec4) == *(int *)(param_1 + 2)) {
    if (param_2 < 6) {
      uVar6 = 0;
    }
    else {
      uVar6 = param_2 - 6 >> 2;
    }
    bVar4 = false;
    local_44 = in_ECX;
    if (uVar6 != 0) {
      psVar11 = (short *)(param_1 + 8);
      local_40 = uVar6;
      do {
        cVar1 = *(char *)((int)psVar11 + -1);
        local_30 = (int)*psVar11;
        bVar2 = *(byte *)(psVar11 + -1);
        puVar10 = (undefined4 *)(*(undefined4 **)(in_ECX + 0x5f40))[1];
        cVar3 = *(char *)((int)puVar10 + 0x19);
        local_34 = CONCAT31(CONCAT21(local_34._2_2_,cVar1),bVar2);
        local_3c = *(undefined4 **)(in_ECX + 0x5f40);
        while (cVar3 == '\0') {
          if (*(byte *)(puVar10 + 3) < bVar2) {
            puVar7 = (undefined4 *)puVar10[2];
            puVar10 = local_3c;
          }
          else {
            puVar7 = (undefined4 *)*puVar10;
          }
          local_3c = puVar10;
          puVar10 = puVar7;
          in_ECX = local_44;
          cVar3 = *(char *)((int)puVar7 + 0x19);
        }
        if ((local_3c == *(undefined4 **)(in_ECX + 0x5f40)) || (bVar2 < *(byte *)(local_3c + 3))) {
          local_38 = *(undefined4 **)(in_ECX + 0x5f40);
          ppuVar8 = &local_38;
        }
        else {
          ppuVar8 = &local_3c;
        }
        puVar10 = *ppuVar8;
        if (puVar10 == *(undefined4 **)(in_ECX + 0x5f40)) {
          bVar4 = true;
          local_20 = local_34;
          local_24 = bVar2;
          local_1c = local_30;
          uVar9 = FUN_004edd10(uVar5);
          FUN_004ed630(local_44 + 0x5f3c,uVar9);
          in_ECX = local_44;
        }
        else {
          if (*(char *)((int)puVar10 + 0x11) != cVar1) {
            bVar4 = true;
          }
          *(byte *)(puVar10 + 4) = bVar2;
          *(char *)((int)puVar10 + 0x11) = cVar1;
          puVar10[5] = local_30;
        }
        psVar11 = psVar11 + 2;
        local_40 = local_40 - 1;
      } while (local_40 != 0);
      if (bVar4) {
        local_44 = CONCAT22(local_44._2_2_,0xee);
        if (DAT_00fba798 == 0) {
          (**(code **)(*DAT_00fba854 + 0x10))(0,&local_44,2);
        }
      }
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    FUN_0058aad0(0xf4259);
  }
  ExceptionList = local_14;
  return 0;
}

