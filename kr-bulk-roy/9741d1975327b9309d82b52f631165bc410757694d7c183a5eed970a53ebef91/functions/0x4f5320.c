
void FUN_004f5320(void)

{
  WCHAR WVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  WCHAR *pWVar5;
  int *piVar6;
  undefined **local_1a4 [3];
  int *local_198;
  undefined2 local_194 [2];
  char local_190 [4];
  int *local_18c;
  undefined4 local_188;
  char *local_180;
  undefined1 local_17c [16];
  undefined4 local_16c;
  undefined4 local_168;
  undefined2 local_160 [8];
  undefined4 local_150;
  undefined4 local_14c;
  undefined1 local_144 [16];
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined1 local_11c;
  undefined1 local_11b;
  WCHAR local_114;
  undefined1 local_112 [254];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927461;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_194[0] = 0;
  local_188 = 0;
  local_18c = (int *)FUN_00891268(0xa4,local_14);
  if (local_18c == (int *)0x0) {
    local_180 = (char *)0x0;
    std::exception::exception((exception *)local_1a4,&local_180);
    local_1a4[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_1a4,&DAT_00c857a8);
  }
  *local_18c = (int)local_18c;
  local_18c[1] = (int)local_18c;
  local_18c[2] = (int)local_18c;
  *(undefined1 *)(local_18c + 0x28) = 1;
  *(undefined1 *)((int)local_18c + 0xa1) = 1;
  local_8 = 0;
  local_194[0] = 0;
  FUN_004ccdd0(local_18c[1]);
  local_18c[1] = (int)local_18c;
  *local_18c = (int)local_18c;
  local_18c[2] = (int)local_18c;
  local_188 = 0;
  iVar2 = FUN_0082bb00(local_194);
  if ((iVar2 != 0) && (local_198 = (int *)*local_18c, local_198 != local_18c)) {
    do {
      piVar4 = local_198;
      local_168 = 0xf;
      local_16c = 0;
      local_17c[0] = 0;
      local_14c = 7;
      local_150 = 0;
      local_160[0] = 0;
      local_130 = 0xf;
      local_134 = 0;
      local_144[0] = 0;
      local_8 = CONCAT31(local_8._1_3_,1);
      if ((uint)local_198[10] < 0x10) {
        piVar6 = local_198 + 5;
      }
      else {
        piVar6 = (int *)local_198[5];
      }
      piVar3 = piVar6;
      do {
        iVar2 = *piVar3;
        piVar3 = (int *)((int)piVar3 + 1);
      } while ((char)iVar2 != '\0');
      FUN_00402a70(piVar6,(int)piVar3 - (int)((int)piVar6 + 1));
      local_180 = (char *)(*(ushort *)(piVar4 + 4) | 0x2000000);
      piVar6 = piVar4 + 0xc;
      piVar3 = piVar6;
      if (0xf < (uint)piVar4[0x11]) {
        piVar3 = (int *)*piVar6;
      }
      MultiByteToWideChar(0,0,(LPCSTR)piVar3,-1,&local_114,0x104);
      if (0xf < (uint)piVar4[0x11]) {
        piVar6 = (int *)*piVar6;
      }
      piVar4 = piVar6;
      do {
        iVar2 = *piVar4;
        piVar4 = (int *)((int)piVar4 + 1);
      } while ((char)iVar2 != '\0');
      FUN_00402a70(piVar6,(int)piVar4 - (int)((int)piVar6 + 1));
      pWVar5 = &local_114;
      do {
        WVar1 = *pWVar5;
        pWVar5 = pWVar5 + 1;
      } while (WVar1 != L'\0');
      FUN_00402160(&local_114,(int)pWVar5 - (int)local_112 >> 1);
      iVar2 = FUN_004f7a70();
      FUN_00403040(local_17c,0,0xffffffff);
      FUN_004026e0(local_160,0,0xffffffff);
      FUN_00403040(local_144,0,0xffffffff);
      *(undefined4 *)(iVar2 + 0x54) = local_128;
      *(undefined4 *)(iVar2 + 0x58) = local_124;
      *(undefined4 *)(iVar2 + 0x5c) = local_120;
      *(undefined1 *)(iVar2 + 0x60) = local_11c;
      *(undefined1 *)(iVar2 + 0x61) = local_11b;
      FUN_004f52b0();
      FUN_004ccf20();
    } while (local_198 != local_18c);
  }
  local_180 = local_190;
  local_8 = 2;
  FUN_004cca50(&local_198,*local_18c,local_18c);
  FUN_0089120c(local_18c);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

