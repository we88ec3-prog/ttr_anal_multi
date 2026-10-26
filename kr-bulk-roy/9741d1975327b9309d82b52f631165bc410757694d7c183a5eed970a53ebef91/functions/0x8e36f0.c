
void FUN_008e36f0(undefined4 param_1,undefined4 param_2,int *param_3,char *param_4,int param_5)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_20 [4];
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  byte local_5;
  
  local_c = FUN_008e1e30();
  local_5 = (byte)local_c & 1;
  if (((local_c & 1) != 0) && (*param_4 == '\0')) {
    iVar1 = FUN_008e0e10();
    iVar2 = FUN_008e1f60();
    *param_3 = iVar1 + iVar2;
  }
  if (*(char *)(*(int *)(in_EAX + 0x84) + 0x2f1) != '\0') {
    *param_4 = '\x01';
    return;
  }
  uVar3 = (uint)(local_5 != 0);
  if (uVar3 < local_c) {
    do {
      iVar1 = FUN_008e1f60();
      local_1c = param_5 + iVar1;
      iVar2 = FUN_008e1f60();
      param_5 = param_5 + iVar1 + iVar2;
      local_14 = 0;
      local_10 = 0;
      local_20[0] = 0;
      local_18 = param_5;
      FUN_008e2300(local_20);
      uVar3 = uVar3 + 2;
    } while (uVar3 < local_c);
  }
  FUN_008e1fb0();
  *param_4 = '\x01';
  return;
}

