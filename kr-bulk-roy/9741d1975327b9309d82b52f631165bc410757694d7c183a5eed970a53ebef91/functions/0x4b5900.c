
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b5900(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  undefined4 *local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_38 [5];
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093a8f5;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  ExceptionList = &local_14;
  local_60 = param_1;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff90);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  iVar1 = FUN_004dfb60();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_00891268(0x48);
    local_c = 1;
    local_64 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2[1] = (uint)*(ushort *)(iVar1 + 4);
      *puVar2 = 10;
      puVar2[2] = 1;
      *(undefined1 *)(puVar2 + 3) = 1;
      puVar2[4] = *(undefined4 *)(iVar1 + 0xa0);
      uVar3 = *(undefined4 *)(iVar1 + 0xa4);
      local_5c = 0;
      puVar2[7] = 0;
      puVar2[5] = uVar3;
      local_58 = 0;
      puVar2[6] = 0;
      puVar2[8] = 0;
      puVar2[0xe] = 7;
      puVar2[0xd] = 0;
      *(undefined2 *)(puVar2 + 9) = 0;
      FUN_00402160(&DAT_00bed1fc,0);
      puVar2[0x10] = 0;
      puVar2[0x11] = 0;
    }
    local_c = 0xffffffff;
    if ((_DAT_00fdf3c0 & 1) == 0) {
      _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
      DAT_00fdf3c4 = 0;
      _atexit((_func_4879 *)&DAT_00bcdf50);
    }
    FUN_0056f5c0(DAT_00fdf3c4,puVar2);
    if ((DAT_00fb72a4 & 1) == 0) {
      DAT_00fb72a4 = DAT_00fb72a4 | 1;
      local_c = 2;
      FUN_0049f850();
      _atexit((_func_4879 *)&LAB_00bccfe0);
      local_c = 0xffffffff;
    }
    FUN_004a05b0(&DAT_00fb72a8,*(undefined1 *)(local_60 + 6));
    if ((DAT_00fdf3d4 & 1) == 0) {
      DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
      local_c = 3;
      FUN_006f4380();
      _atexit((_func_4879 *)&LAB_00bce6d0);
      local_c = 0xffffffff;
    }
    FUN_006f5680();
    iVar1 = local_60;
    if ((*(undefined **)(DAT_00fdf3c8 + 8) == &DAT_00c0bfd8) ||
       (*(int *)(*(undefined **)(DAT_00fdf3c8 + 8) + -8) != 5)) {
      FID_conflict__wprintf("Error UseTable \'%s\'\n","VoiceMacroMessage");
    }
    else {
      local_64 = (undefined4 *)0x0;
      FUN_004b7ca0(&DAT_00fdf3c8,*(undefined1 *)(local_60 + 6),&local_64);
      if (local_64 != (undefined4 *)0x0) {
        FUN_00402b70(local_64);
        local_c = 4;
        puVar2 = (undefined4 *)FUN_004028b0(local_38);
        local_c = CONCAT31(local_c._1_3_,5);
        if (7 < (uint)puVar2[5]) {
          puVar2 = (undefined4 *)*puVar2;
        }
        uVar3 = *(undefined4 *)(iVar1 + 2);
        FUN_00425330(extraout_ECX,uVar3);
        uVar3 = FUN_004f6a30(uVar3);
        FUN_0040f8c0(puVar2,uVar3);
        FUN_004d6c70();
        if (7 < local_40) {
          FUN_0089120c(local_54);
        }
        local_40 = 7;
        local_44 = 0;
        local_54 = local_54 & 0xffff0000;
        if (0xf < local_24) {
          FUN_0089120c(local_38[0]);
        }
      }
    }
    *(int *)(DAT_00fdf3c8 + 8) = *(int *)(DAT_00fdf3c8 + 8) + -0x10;
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_64);
  return;
}

