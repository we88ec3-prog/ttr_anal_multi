
void FUN_006dcd30(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *_Dst;
  void *_Src;
  int *piVar4;
  int in_ECX;
  undefined1 local_94 [64];
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938392;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x10) != 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(local_14);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    piVar4 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
    (**(code **)(*piVar4 + 0xb4))(piVar4,2,local_94);
    (**(code **)(*piVar4 + 0xb4))(piVar4,3,local_54);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb773c + 0x10))(DAT_00fb773c);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb7738 + 0x14))(DAT_00fb7738);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 3;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 4;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
    }
    (**(code **)(**(int **)(in_ECX + 8) + 0x28))(DAT_00fb76a8);
    piVar1 = (int *)(in_ECX + 0x90);
    (**(code **)(*piVar4 + 0x98))(piVar4,0,piVar1);
    piVar2 = (int *)(in_ECX + 0x94);
    (**(code **)(*piVar4 + 0xa0))(piVar4,piVar2);
    (**(code **)(*piVar4 + 0xc0))(piVar4,in_ECX + 0x98);
    (**(code **)(*piVar4 + 0x94))(piVar4,0,*(undefined4 *)(in_ECX + 0x88));
    (**(code **)(*piVar4 + 0x9c))(piVar4,*(undefined4 *)(in_ECX + 0x8c));
    (**(code **)(*piVar4 + 0xac))(piVar4,0,0,7,0x2d3232,0x3f800000,0);
    (**(code **)(*piVar4 + 0xa4))(piVar4);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x8b,0xffffffff);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x89,0);
    (**(code **)(**(int **)(in_ECX + 0x10) + 8))();
    _Dst = *(void **)(DAT_00fba838 + 0xb4);
    puVar3 = (undefined4 *)(DAT_00fba838 + 0xb8);
    _Src = (void *)*puVar3;
    if (_Dst != _Src) {
      FID_conflict__memcpy(_Dst,_Src,0);
      *puVar3 = _Dst;
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 5;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    FUN_00799f20();
    (**(code **)(*piVar4 + 0xa8))(piVar4);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 6;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb773c + 0x14))(DAT_00fb773c);
    (**(code **)(*piVar4 + 0x94))(piVar4,0,*piVar1);
    (**(code **)(*piVar4 + 0x9c))(piVar4,*piVar2);
    (**(code **)(*piVar4 + 0xbc))(piVar4,in_ECX + 0x98);
    (**(code **)(*piVar4 + 0xb0))(piVar4,2,local_94);
    (**(code **)(*piVar4 + 0xb0))(piVar4,3,local_54);
    piVar4 = (int *)*piVar1;
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))(piVar4);
      *piVar1 = 0;
    }
    piVar4 = (int *)*piVar2;
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))(piVar4);
      *piVar2 = 0;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

