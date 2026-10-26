
int FUN_008f2f70(int *param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if ((char)param_1[0x49] == '\0') {
    iVar3 = *(int *)(*(int *)(iVar1 + 0x60) + 0x1c);
  }
  else {
    iVar3 = param_1[0x4a];
  }
  if (iVar3 != 0) {
    FUN_008ec000(iVar3,iVar1);
    *(undefined1 *)(iVar3 + 0x231) = param_2;
    *(undefined4 *)(iVar3 + 0x1ac) = 0;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 0x1dc) = 0x40;
    *(undefined4 *)(iVar3 + 0x1e0) = 0;
    *(undefined4 *)(iVar3 + 0x1e4) = 0;
    *(undefined1 *)(iVar3 + 0x1e8) = 0;
    *(undefined4 *)(iVar3 + 0x234) = 0x4000;
    *(undefined4 *)(iVar3 + 0xd8) = 0;
    *(undefined4 *)(iVar3 + 0xdc) = 0;
    *(undefined4 *)(iVar3 + 0xe0) = 0;
    *(undefined2 *)(iVar3 + 0xfc) = 0;
    *(undefined4 *)(iVar3 + 0x104) = 0;
    *(undefined4 *)(iVar3 + 0x100) = 0x10000;
    FUN_008ebea0(*(undefined4 *)(iVar1 + 0x274));
    FUN_008ebec0();
    FUN_008ebec0();
    if (*(int *)(iVar1 + 0x274) == 0) {
      FUN_008ec220();
      return 0;
    }
    iVar2 = FUN_008ebe70(0);
    if ((iVar2 == 0) && (iVar2 = (**(code **)(iVar1 + 0x28c))(iVar3), iVar2 == 0)) {
      FUN_008ec220();
    }
    return iVar2;
  }
  return 0x99;
}

