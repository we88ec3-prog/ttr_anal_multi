
undefined4 * FUN_00721540(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  char *_Str1;
  int iVar3;
  char *unaff_EDI;
  
  uVar2 = FUN_0071cde0();
  puVar1 = *(undefined4 **)(param_1 + (uVar2 & 0x3f) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    switch(*puVar1) {
    case 1:
      _Str1 = (char *)(puVar1 + 7);
      break;
    case 2:
      _Str1 = (char *)(puVar1 + 4);
      break;
    case 3:
      _Str1 = (char *)(puVar1 + 3);
      break;
    case 4:
      _Str1 = (char *)((int)puVar1 + 9);
      break;
    default:
      _Str1 = (char *)0x0;
    }
    iVar3 = __stricmp(_Str1,unaff_EDI);
    if (iVar3 == 0) break;
    puVar1 = (undefined4 *)puVar1[1];
  }
  return puVar1;
}

