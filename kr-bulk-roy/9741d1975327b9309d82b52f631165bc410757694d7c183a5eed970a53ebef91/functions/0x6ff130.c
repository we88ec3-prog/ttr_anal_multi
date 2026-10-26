
void FUN_006ff130(int param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_64 [4];
  undefined1 local_60 [84];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_64;
  FUN_006f7c50(local_60);
  uVar2 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),"%s(%d) : error: %s",local_60,
                       *(undefined4 *)(param_1 + 4),param_2);
  if (param_3 != 0) {
    uVar3 = FUN_006ff0c0();
    FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),"%s near \'%s\'",uVar2,uVar3);
  }
  FUN_006fdb40(*(undefined4 *)(param_1 + 0x34),3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

