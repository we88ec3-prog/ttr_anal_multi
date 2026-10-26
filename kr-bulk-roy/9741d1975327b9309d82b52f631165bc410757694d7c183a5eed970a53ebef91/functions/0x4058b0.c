
void FUN_004058b0(void)

{
  byte bVar1;
  int *piVar2;
  int *in_ECX;
  ushort local_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  byte local_16;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b716;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 10) & 0x10) == 0) {
    if (in_ECX[0x18] == 0) goto LAB_00405915;
    piVar2 = (int *)FUN_00745c20();
  }
  if ((((piVar2 != (int *)0x0) && (piVar2[0x18] != 0)) && (((uint)piVar2[10] >> 0xc & 1) == 0)) &&
     (piVar2[0x18] != 0)) {
    FUN_0074a010(piVar2);
  }
LAB_00405915:
  FUN_00405b20(in_ECX);
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_8 = 0;
    FUN_004073c0();
    _atexit((_func_4879 *)&LAB_00bcccd0);
    local_8 = 0xffffffff;
  }
  local_1c = 0xea;
  uStack_1a = (undefined2)DAT_00faaf40;
  uStack_18 = (undefined2)((uint)DAT_00faaf40 >> 0x10);
  local_16 = DAT_00faaf38;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1c,7);
  }
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_8 = 1;
    FUN_004073c0();
    _atexit((_func_4879 *)&LAB_00bcccd0);
    local_8 = 0xffffffff;
  }
  bVar1 = *(byte *)((uint)DAT_00faaf38 + DAT_00faaf5c);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 2;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  if (DAT_00f94568 != 0) {
    local_14 = (uint)bVar1;
    FUN_0082ef00(&local_14);
  }
  FUN_00745060();
  (**(code **)(*(int *)in_ECX[0x93] + 200))();
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_8 = 3;
    FUN_004073c0();
    _atexit((_func_4879 *)&LAB_00bcccd0);
    local_8 = 0xffffffff;
  }
  bVar1 = *(byte *)((uint)DAT_00faaf38 + DAT_00faaf6c);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 4;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  if (DAT_00f9456c != 0) {
    local_1c = (ushort)bVar1;
    uStack_1a = 0;
    FUN_0082ef00(&local_1c);
  }
  FUN_00745060();
  (**(code **)(*(int *)in_ECX[0x94] + 200))();
  FUN_00406050(in_ECX);
  (**(code **)(*in_ECX + 200))();
  ExceptionList = local_10;
  return;
}

