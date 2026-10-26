
undefined4 FUN_004a48f0(int param_1,int param_2)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  short *psVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  undefined4 uVar7;
  uint in_ECX;
  undefined4 *puVar8;
  short *local_50;
  uint local_4c;
  uint local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  short *local_3c;
  char *local_38;
  short local_34;
  short *local_30;
  undefined **local_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00913369;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  *(undefined1 *)(param_1 + 0x14) = 1;
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_004a4d30(param_1,uVar3);
  if (in_ECX < 9) {
    local_4c = 0;
  }
  else {
    local_4c = (in_ECX - 9) / 7;
  }
  local_48 = 0;
  if (local_4c != 0) {
    local_50 = (short *)(param_2 + 9);
    do {
      local_3c = (short *)FUN_00891268(0x84);
      local_c = 0;
      if (local_3c == (short *)0x0) {
        psVar4 = (short *)0x0;
      }
      else {
        psVar4 = (short *)FUN_00827d50(local_3c);
      }
      local_3c = psVar4;
      if ((DAT_00fd93f4 & 1) == 0) {
        DAT_00fd93f4 = DAT_00fd93f4 | 1;
        local_c = 1;
        DAT_00fd9400 = 0;
        puVar5 = (undefined4 *)FUN_00891268(0x98);
        if (puVar5 == (undefined4 *)0x0) {
          local_38 = (char *)0x0;
          std::exception::exception((exception *)local_24,&local_38);
          local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_24,&DAT_00c857a8);
        }
        DAT_00fd93fc = puVar5;
        *puVar5 = puVar5;
        DAT_00fd93fc[1] = DAT_00fd93fc;
        DAT_00fd93fc[2] = DAT_00fd93fc;
        *(undefined1 *)(DAT_00fd93fc + 0x25) = 1;
        *(undefined1 *)((int)DAT_00fd93fc + 0x95) = 1;
        _atexit(FUN_00bcde40);
      }
      local_c = 0xffffffff;
      sVar2 = *local_50;
      cVar1 = *(char *)((int)DAT_00fd93fc[1] + 0x95);
      puVar5 = (undefined4 *)DAT_00fd93fc[1];
      local_44 = DAT_00fd93fc;
      while (puVar8 = puVar5, cVar1 == '\0') {
        if (*(short *)(puVar8 + 3) < sVar2) {
          puVar5 = (undefined4 *)puVar8[2];
          puVar8 = local_44;
        }
        else {
          puVar5 = (undefined4 *)*puVar8;
        }
        cVar1 = *(char *)((int)puVar5 + 0x95);
        local_44 = puVar8;
      }
      if ((local_44 == DAT_00fd93fc) || (sVar2 < *(short *)(local_44 + 3))) {
        local_40 = DAT_00fd93fc;
        ppuVar6 = &local_40;
      }
      else {
        ppuVar6 = &local_44;
      }
      if (*ppuVar6 == DAT_00fd93fc) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        puVar5 = *ppuVar6 + 4;
      }
      *psVar4 = sVar2;
      *(undefined4 *)(psVar4 + 0x2e) = *(undefined4 *)(local_50 + 1);
      if (puVar5 == (undefined4 *)0x0) {
        FUN_00827e30();
        FUN_0089120c(psVar4);
        psVar4 = (short *)0x0;
      }
      else {
        *(undefined4 *)(psVar4 + 0x32) = puVar5[0x19];
        FUN_004026e0(puVar5 + 1,0,0xffffffff);
        FUN_004026e0(puVar5 + 8,0,0xffffffff);
        *(undefined4 *)(psVar4 + 0x36) = puVar5[0x1b];
        FUN_004026e0(puVar5 + 0xf,0,0xffffffff);
        local_34 = *psVar4;
        *(undefined4 *)(psVar4 + 0x38) = puVar5[0x1c];
        local_30 = psVar4;
        uVar7 = FUN_004ca670();
        FUN_004a4df0(param_1,uVar7);
        psVar4 = local_3c;
      }
      if (((char)local_50[3] != '\0') && (psVar4 != (short *)0x0)) {
        *(short **)(param_1 + 0x10) = psVar4;
        *(undefined1 *)(psVar4 + 0x34) = 1;
      }
      local_50 = (short *)((int)local_50 + 7);
      local_48 = local_48 + 1;
    } while (local_48 < local_4c);
  }
  ExceptionList = local_14;
  return 0;
}

