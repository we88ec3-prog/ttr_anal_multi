
void FUN_0065db90(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piVar4;
  int iVar5;
  undefined1 auStack_25c [4];
  uint uStack_258;
  uint uStack_254;
  int iStack_250;
  int iStack_24c;
  uint uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_234;
  uint uStack_230;
  undefined1 auStack_220 [516];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009487e5;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_25c;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xfffffd98);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if ((DAT_00fba7a4 != (int *)0x0) && (iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))(), iVar2 != 0)) {
    uVar1 = *(ushort *)(iVar2 + 0x88);
    if (*(int *)(*(int *)(in_ECX + 0xf4) + 0xcc) != 0) {
      FUN_0042c8e0(uVar1 - 1);
    }
    (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
    FUN_0065d9a0(in_ECX,(uint)uVar1);
    iVar2 = FUN_00404ba0();
    uStack_244 = (uint)*(ushort *)(iVar2 + 0x6860);
    uStack_254 = 1;
    uStack_258 = 1;
    iStack_250 = 0x210;
    piVar4 = (int *)(in_ECX + 0x100);
    iStack_24c = 9;
    do {
      iVar5 = iStack_250;
      FUN_0040aeb0(L"BotCha%02d",uStack_258);
      uStack_240 = FUN_00763360(auStack_220);
      iVar2 = *piVar4;
      if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
         (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
        FUN_0077b200();
        iVar5 = iStack_250;
      }
      *(uint *)(*piVar4 + 0x28) = *(uint *)(*piVar4 + 0x28) | 4;
      (**(code **)(*(int *)*piVar4 + 200))();
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 1;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      if (((uStack_258 < 10) && (*(int *)(iVar5 + 0x5c + DAT_00f94304) != 0)) &&
         ((iVar5 + DAT_00f94304 != 0 &&
          ((*(int *)(iVar5 + DAT_00f94304 + 0x5c) != 0 && ((uStack_254 & uStack_244 & 0xffff) != 0))
          )))) {
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 2;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        (**(code **)(*(int *)piVar4[0x12] + 0x94))(0);
        (**(code **)(*(int *)*piVar4 + 0x90))(1);
        uVar3 = FUN_0040ef80();
        local_14 = (void *)0x3;
        FUN_00757800(uVar3);
        local_14 = (void *)0xffffffff;
        if (7 < uStack_230) {
          FUN_0089120c(uStack_244);
        }
        uStack_230 = 7;
        uStack_234 = 0;
        uStack_244 = uStack_244 & 0xffff0000;
      }
      else {
        (**(code **)(*(int *)*piVar4 + 0x90))(0);
        (**(code **)(*(int *)piVar4[0x12] + 0x94))(1);
        FUN_00757710();
      }
      (**(code **)(*(int *)piVar4[9] + 200))();
      uStack_258 = uStack_258 + 1;
      iStack_250 = iVar5 + 0x210;
      piVar4 = piVar4 + 1;
      uStack_254 = uStack_254 << 1 | (uint)((int)uStack_254 < 0);
      iStack_24c = iStack_24c + -1;
    } while (iStack_24c != 0);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_25c);
  return;
}

