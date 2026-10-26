
void FUN_004c9b60(undefined4 param_1,float param_2,float param_3,float param_4,undefined4 param_5,
                 undefined4 param_6,int *param_7)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  float *pfVar4;
  int xRight;
  int yTop;
  int xLeft;
  undefined4 *in_ECX;
  undefined4 uVar5;
  float10 fVar6;
  undefined1 auStack_84 [4];
  float fStack_80;
  float fStack_7c;
  undefined4 *local_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  undefined1 local_64 [44];
  tagRECT tStack_38;
  float local_28;
  undefined4 uStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  piVar1 = param_7;
  puStack_10 = &LAB_00933e94;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  local_78 = in_ECX;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  if ((DAT_00fb76e4 == 0) || (iVar3 = FUN_00838800(param_2,param_3,param_4), iVar3 != 0)) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    iVar3 = DAT_00fb76e8;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 2;
      FUN_00798de0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    FUN_0079b910(&DAT_00fb76a8,&param_2);
    pfVar4 = (float *)(**(code **)(**(int **)(iVar3 + 4) + 0x24))(local_64);
    fStack_74 = *pfVar4;
    fStack_70 = pfVar4[1];
    fStack_6c = pfVar4[2];
    fStack_68 = fStack_74 - param_2;
    fStack_7c = fStack_70 - param_3;
    fStack_80 = (fStack_6c - param_4) * (fStack_6c - param_4) +
                fStack_68 * fStack_68 + fStack_7c * fStack_7c;
    fVar6 = (float10)FUN_008ff870();
    fStack_80 = (float)fVar6;
    fStack_7c = fStack_80;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 3;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    FUN_0079a5f0(&DAT_00fb76a8);
    if (fStack_7c <= 250.0) {
      local_28 = local_28 + 0.5;
      iVar3 = FUN_008fed10();
      xRight = FUN_008fed10();
      yTop = FUN_008fed10();
      xLeft = FUN_008fed10();
      SetRect(&tStack_38,xLeft,yTop,xRight,iVar3);
      if (piVar1 != (int *)0x0) {
        tStack_38.left = tStack_38.left + *piVar1;
        tStack_38.right = tStack_38.right + *piVar1;
        tStack_38.top = tStack_38.top + piVar1[1];
        tStack_38.bottom = tStack_38.bottom + piVar1[1];
      }
      if ((DAT_00fcde44 & 1) == 0) {
        DAT_00fcde44 = DAT_00fcde44 | 1;
        local_c = 4;
        FUN_0055b8a0();
        _atexit(FUN_00bcdef0);
        local_c = 0xffffffff;
      }
      if (10.0 <= fStack_7c) {
        uVar5 = FUN_0055c4b0(fStack_7c);
      }
      else {
        uVar5 = 5;
      }
      if ((DAT_00fcde44 & 1) == 0) {
        DAT_00fcde44 = DAT_00fcde44 | 1;
        local_c = 5;
        FUN_0055b8a0();
        _atexit(FUN_00bcdef0);
        local_c = 0xffffffff;
      }
      FUN_0055bbe0(param_1,uStack_20,uVar5,param_5,param_6,local_78);
    }
    else if (local_78 != (undefined4 *)0x0) {
      (**(code **)*local_78)(1);
    }
  }
  else if (in_ECX != (undefined4 *)0x0) {
    (**(code **)*in_ECX)(1);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}

