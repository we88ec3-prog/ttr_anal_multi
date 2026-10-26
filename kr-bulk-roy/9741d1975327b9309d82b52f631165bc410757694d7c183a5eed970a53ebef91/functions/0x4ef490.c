
undefined4 FUN_004ef490(uint param_1,int param_2,short *param_3)

{
  undefined4 *puVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  short *psVar7;
  uint uVar8;
  short *psVar9;
  undefined **local_24 [3];
  char *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar3 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092493e;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1 = 0;
  if ((1 < param_3) && (local_14 = ((int)param_3 - 2U) / 0x61, local_14 != 0)) {
    psVar9 = (short *)(param_2 + 10);
    do {
      iVar5 = FUN_00891268(200,uVar4);
      if (iVar5 == 0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        puVar6 = (undefined4 *)FUN_004ef0d0();
      }
      param_3 = psVar9 + 0x16;
      psVar7 = psVar9 + 0x15;
      do {
        sVar2 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar9 + 0x15,(int)psVar7 - (int)param_3 >> 1);
      *puVar6 = *(undefined4 *)(psVar9 + -4);
      puVar6[1] = *(undefined4 *)(psVar9 + -2);
      psVar7 = psVar9;
      do {
        sVar2 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar9,(int)psVar7 - (int)(psVar9 + 1) >> 1);
      *(short *)(puVar6 + 0x18) = psVar9[0x2a];
      *(char *)((int)puVar6 + 0x62) = (char)psVar9[0x2b];
      *(undefined1 *)((int)puVar6 + 99) = *(undefined1 *)((int)psVar9 + 0x57);
      *(bool *)(puVar6 + 9) = (char)psVar9[0x2c] != '\0';
      FUN_004ef080();
      if (((*(int *)(iVar3 + 0xc) + *(int *)(iVar3 + 0x10) & 3U) == 0) &&
         (*(uint *)(iVar3 + 8) <= *(int *)(iVar3 + 0x10) + 4U >> 2)) {
        FUN_00636f70(iVar3);
      }
      uVar8 = *(int *)(iVar3 + 0xc) + *(int *)(iVar3 + 0x10);
      param_3 = (short *)(uVar8 >> 2);
      if (*(uint *)(iVar3 + 8) <= param_3) {
        param_3 = (short *)((int)param_3 - *(uint *)(iVar3 + 8));
      }
      if (*(int *)(*(int *)(iVar3 + 4) + (int)param_3 * 4) == 0) {
        iVar5 = FUN_00891268(0x10);
        if (iVar5 == 0) {
          local_18 = (char *)0x0;
          std::exception::exception((exception *)local_24,&local_18);
          local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_24,&DAT_00c857a8);
        }
        *(int *)(*(int *)(iVar3 + 4) + (int)param_3 * 4) = iVar5;
      }
      puVar1 = (undefined4 *)(*(int *)(*(int *)(iVar3 + 4) + (int)param_3 * 4) + (uVar8 & 3) * 4);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = puVar6;
      }
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
      param_1 = param_1 + 1;
      psVar9 = (short *)((int)psVar9 + 0x61);
    } while (param_1 < local_14);
  }
  param_3 = (short *)CONCAT22(0x96,param_3._0_2_);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_3 + 2,2);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4270);
  ExceptionList = local_10;
  return 0;
}

