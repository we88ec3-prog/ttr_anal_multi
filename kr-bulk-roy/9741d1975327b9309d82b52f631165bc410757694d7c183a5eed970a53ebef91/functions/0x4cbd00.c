
void FUN_004cbd00(undefined4 param_1)

{
  undefined4 uVar1;
  byte bVar2;
  undefined2 uVar3;
  uint uVar4;
  DWORD DVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092115e;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar4;
  FUN_004cb4b0(param_1);
  DVar5 = timeGetTime();
  if (200 < DVar5 - *(int *)(in_ECX + 0x38)) {
    puVar6 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))(uVar4);
    local_20 = *puVar6;
    local_1c = puVar6[1];
    local_18 = puVar6[2];
    bVar2 = *(byte *)(*(int *)(in_ECX + 4) + 0xb0);
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0();
    }
    uVar3 = *(undefined2 *)(*(int *)(in_ECX + 4) + 4);
    uVar1 = (&DAT_00fb7c20)[bVar2];
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      local_8 = 0;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      local_8 = 0xffffffff;
    }
    FUN_00551b80(0xffffffff,0xffffffff);
    FUN_00551dd0(&DAT_00fdf680,uVar3,&local_20,uVar1,0x3f800000,1);
    DVar5 = timeGetTime();
    *(DWORD *)(in_ECX + 0x38) = DVar5;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

