
void FUN_00543b30(int *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  char in_CL;
  undefined1 auStack_4c [7];
  char local_45;
  undefined4 *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  char *local_34;
  undefined4 *local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009297ac;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_4c;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  *(char *)((int)param_1 + 0x105) = in_CL;
  if ((short)param_1[0x3d] != 0) {
    if ((((short)param_1[0x3d] == 4) && (in_CL == '\0')) && (param_1[0x3c] != 0)) {
      if (*(int *)(param_1[0x3c] + 0x24) != 0) {
        FUN_007be5f0(uVar1);
      }
      if (param_1[0x3c] != 0) {
        FUN_004c7db0();
        param_1[0x3c] = 0;
      }
    }
    goto LAB_00543fff;
  }
  local_45 = in_CL;
  if (param_1[0x3c] != 0) {
    if (*(int *)(param_1[0x3c] + 0x24) != 0) {
      FUN_007be5f0(uVar1);
    }
    if (param_1[0x3c] != 0) {
      FUN_004c7db0();
      param_1[0x3c] = 0;
    }
  }
  if (local_45 == '\x01') {
    if ((char)param_1[0x3e] == '\0') {
      puVar2 = (undefined4 *)FUN_00891268(0x48);
      local_c = 0;
      local_44 = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = (int)*(short *)((int)param_1 + 0xf6);
        *puVar2 = 8;
        puVar2[2] = 4;
        *(undefined1 *)(puVar2 + 3) = 1;
        puVar2[4] = param_1[0x28];
        puVar2[5] = param_1[0x29];
        puVar2[7] = 0;
        puVar2[8] = 0;
        goto LAB_00543ca0;
      }
LAB_00543ccf:
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)FUN_00891268(0x48);
      local_c = 1;
      local_44 = puVar2;
      if (puVar2 == (undefined4 *)0x0) goto LAB_00543ccf;
      puVar2[1] = (int)*(short *)((int)param_1 + 0xf6);
      *puVar2 = 0xb;
      puVar2[2] = 2;
      *(undefined1 *)(puVar2 + 3) = 1;
      puVar2[4] = param_1[0x28];
      puVar2[5] = param_1[0x29];
      puVar2[7] = 0;
      puVar2[8] = 0;
LAB_00543ca0:
      local_3c = 0;
      local_40 = 0;
      puVar2[6] = 0;
      puVar2[0xe] = 7;
      puVar2[0xd] = 0;
      *(undefined2 *)(puVar2 + 9) = 0;
      local_44 = puVar2;
      FUN_00402160(&DAT_00bed1fc,0);
      puVar2[0x10] = 0;
      puVar2[0x11] = 0;
    }
    local_c = 0xffffffff;
    puVar3 = (undefined4 *)FUN_00489fb0();
    FUN_0056f5c0(*puVar3,puVar2);
    if ((char)param_1[0x3e] == '\0') {
      local_24 = 0xf;
      local_28 = (undefined4 *)0x0;
      local_38 = local_38 & 0xffffff00;
      FUN_0040b310("OPEN_POTAL");
      local_c = 2;
      uVar4 = FUN_0040b3f0();
      piVar5 = (int *)FUN_0080ab00(uVar4);
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x14))();
      }
      local_c = 0xffffffff;
      if (0xf < local_24) {
        FUN_0089120c(local_38);
      }
      FUN_004adca0();
      FUN_005532d0();
    }
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 3;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_c = 0xffffffff;
    }
    local_44 = (undefined4 *)((uint)(ushort)(short)(char)param_1[0x3e] << 0x10 | 1);
    local_28 = (undefined4 *)FUN_004f7cc0();
    if (0xf < (uint)local_28[5]) {
      local_28 = (undefined4 *)*local_28;
    }
    local_38 = 3;
    local_34 = "PORTAL";
    if ((DAT_00fdf6dc & 1) == 0) {
      local_c = 4;
LAB_00543f74:
      local_34 = "PORTAL";
      local_38 = 3;
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      local_c = 0xffffffff;
    }
  }
  else {
    if ((char)param_1[0x3e] == '\0') {
      puVar2 = (undefined4 *)FUN_00891268(0x48);
      local_c = 5;
      local_44 = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        iVar6 = (int)*(short *)((int)param_1 + 0xf6);
        *puVar2 = 8;
        puVar2[2] = iVar6 + 1;
        goto LAB_00543e66;
      }
LAB_00543ecf:
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)FUN_00891268(0x48);
      local_c = 6;
      local_44 = puVar2;
      if (puVar2 == (undefined4 *)0x0) goto LAB_00543ecf;
      iVar6 = (int)*(short *)((int)param_1 + 0xf6);
      *puVar2 = 0xb;
      puVar2[2] = 1;
LAB_00543e66:
      puVar2[1] = iVar6;
      *(undefined1 *)(puVar2 + 3) = 1;
      puVar2[4] = param_1[0x28];
      puVar2[5] = param_1[0x29];
      puVar2[6] = 0;
      local_40 = 0;
      puVar2[7] = 0;
      local_3c = 0;
      puVar2[8] = 0;
      puVar2[0xe] = 7;
      puVar2[0xd] = 0;
      *(undefined2 *)(puVar2 + 9) = 0;
      local_44 = puVar2;
      FUN_00402160(&DAT_00bed1fc,0);
      puVar2[0x10] = 0;
      puVar2[0x11] = 0;
    }
    local_c = 0xffffffff;
    puVar3 = (undefined4 *)FUN_00489fb0();
    FUN_0056f5c0(*puVar3,puVar2);
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 7;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_c = 0xffffffff;
    }
    local_44 = (undefined4 *)CONCAT22((short)(char)param_1[0x3e],(short)local_45);
    local_28 = (undefined4 *)FUN_004f7cc0();
    if (0xf < (uint)local_28[5]) {
      local_28 = (undefined4 *)*local_28;
    }
    local_38 = 3;
    local_34 = "PORTAL";
    if ((DAT_00fdf6dc & 1) == 0) {
      local_c = 8;
      goto LAB_00543f74;
    }
  }
  iVar6 = param_1[0x2d];
  uVar4 = 0;
  (**(code **)(*param_1 + 0x4c))(0,iVar6);
  iVar6 = FUN_00551f90(0,uVar4,iVar6);
  param_1[0x3c] = iVar6;
LAB_00543fff:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_4c);
  return;
}

