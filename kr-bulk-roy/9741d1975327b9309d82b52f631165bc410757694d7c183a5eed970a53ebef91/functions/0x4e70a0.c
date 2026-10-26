
undefined4 FUN_004e70a0(int param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x68f9) = *(undefined1 *)(param_1 + 3);
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
    param_1 = 0xf;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&param_1);
    if (in_ECX == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
  }
  else if (cVar1 == '\x01') {
    param_1 = 0xe4;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&param_1);
    if (in_ECX == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
  }
  else {
    if (cVar1 != '\x02') {
      return 0;
    }
    param_1 = 0x1c8;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&param_1);
    if (in_ECX == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
  }
  puVar5 = (undefined4 *)(in_ECX + 0x10);
  if (7 < *(uint *)(in_ECX + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  FUN_00404b10(0xca,puVar5,&DAT_00bed1fc,0,0);
  return 0;
}

