
void FUN_007d0920(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  int in_ECX;
  char *in_EDX;
  undefined1 local_88 [4];
  int local_84;
  undefined *local_80;
  char *local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  uint local_6c [3];
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  int *local_54;
  uint local_50 [4];
  undefined4 local_40;
  uint local_3c;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00932382;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_78 = 0;
  local_74 = 0;
  local_80 = &DAT_00fbab64;
  local_7c = in_EDX;
  local_18 = uVar2;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fbab64);
  local_8 = 0;
  local_3c = 0xf;
  local_40 = 0;
  local_50[0] = local_50[0] & 0xffffff00;
  pcVar3 = in_EDX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  local_8._0_1_ = 1;
  FUN_007b86f0(&local_84,local_50);
  local_8._0_1_ = 0;
  if (0xf < local_3c) {
    FUN_0089120c(local_50[0],uVar2);
  }
  if (local_84 == *(int *)(in_ECX + 4)) {
    piVar4 = (int *)FUN_00891268(0xc);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      *piVar4 = 0;
      piVar4[1] = 0;
      piVar4[2] = 0;
    }
    piVar4[1] = 1;
    local_74 = 1;
    *piVar4 = 0;
    local_5c = 0xf;
    local_60 = 0;
    local_70 = local_70 & 0xffffff00;
    pcVar3 = local_7c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(local_7c,(int)pcVar3 - (int)(local_7c + 1));
    local_8 = CONCAT31(local_8._1_3_,2);
    iVar7 = **(int **)(in_ECX + 4);
    local_54 = piVar4;
    iVar5 = FUN_00719b90(iVar7,*(undefined4 *)(iVar7 + 4),&local_70);
    if (*(int *)(in_ECX + 8) == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
    *(int *)(iVar7 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    FUN_007d1080(local_88,**(int **)(in_ECX + 4) + 8,**(int **)(in_ECX + 4));
    in_EDX = local_7c;
    if (0xf < local_5c) {
      FUN_0089120c(local_70);
      in_EDX = local_7c;
    }
  }
  else {
    piVar4 = *(int **)(local_84 + 0x24);
    piVar4[1] = piVar4[1] + 1;
  }
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fbab64);
  iVar7 = *piVar4;
  if ((iVar7 == 1) && (piVar4[2] != 0)) {
    puVar6 = (undefined *)FUN_00891268(0x104);
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
    local_80 = puVar6;
    if (puVar6 != (undefined *)0x0) {
      FUN_00402b70(in_EDX);
      local_8._0_1_ = 4;
      local_78 = 1;
      FUN_007d0660(puVar6,piVar4[2],local_6c);
    }
    if ((local_78 & 1) == 0) goto LAB_007d0df1;
  }
  else {
    if (local_74 == 0) {
      while (iVar7 != 3) {
        if ((*piVar4 == 1) && (piVar4[2] != 0)) {
          puVar6 = (undefined *)FUN_00891268(0x104);
          local_8._0_1_ = 6;
          local_8._1_3_ = 0;
          local_80 = puVar6;
          if (puVar6 != (undefined *)0x0) {
            FUN_00402b70(in_EDX);
            local_8._0_1_ = 7;
            local_78 = 2;
            FUN_007d0660(puVar6,piVar4[2],local_6c);
          }
          if ((local_78 & 2) != 0) {
            FUN_00402c50();
          }
          goto LAB_007d0df1;
        }
        Sleep(10);
        iVar7 = *piVar4;
      }
      FUN_007d0e10();
      goto LAB_007d0df1;
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8._0_1_ = 9;
      local_8._1_3_ = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_74 = DAT_00fb76a8;
    local_84 = 0;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8._0_1_ = 10;
      local_8._1_3_ = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
    local_20 = 0xf;
    local_24 = 0;
    local_34 = local_34 & 0xffffff00;
    local_8._1_3_ = 0;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8._0_1_ = 0xc;
      local_8._1_3_ = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8._0_1_ = 0xb;
    iVar7 = FUN_0079bce0(&DAT_00fb76a8);
    if (iVar7 == 0) {
      iVar7 = FUN_007cbee0(local_74,&local_84);
    }
    else {
      iVar7 = FUN_007cbf70(local_74,&local_84);
    }
    iVar5 = local_84;
    if (iVar7 == 0) {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8._0_1_ = 0xd;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8._0_1_ = 0xb;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
      *piVar4 = 3;
      FUN_007d0e10();
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
      goto LAB_007d0df1;
    }
    FUN_007d07e0(local_74,local_84,param_1);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8._0_1_ = 0xe;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8._0_1_ = 0xb;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
    piVar4[2] = iVar5;
    *piVar4 = 1;
    puVar6 = (undefined *)FUN_00891268(0x104);
    local_8._0_1_ = 0xf;
    local_80 = puVar6;
    if (puVar6 != (undefined *)0x0) {
      FUN_00402b70(local_7c);
      local_8._0_1_ = 0x10;
      local_78 = 4;
      FUN_007d0660(puVar6,piVar4[2],local_50);
    }
    local_6c[0] = local_34;
    local_58 = local_20;
    if ((local_78 & 4) != 0) {
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      local_3c = 0xf;
      local_40 = 0;
      local_50[0] = local_50[0] & 0xffffff00;
      local_6c[0] = local_34;
      local_58 = local_20;
    }
  }
  if (0xf < local_58) {
    FUN_0089120c(local_6c[0]);
  }
LAB_007d0df1:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

