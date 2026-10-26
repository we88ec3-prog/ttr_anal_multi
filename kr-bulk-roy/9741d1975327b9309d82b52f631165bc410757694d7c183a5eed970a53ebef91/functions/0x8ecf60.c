
undefined4 FUN_008ecf60(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  ushort in_CX;
  ushort in_DX;
  
  if ((in_CX < *(ushort *)(in_EAX + 0x74)) && (in_DX < *(ushort *)(in_EAX + 0x50))) {
    FUN_008ecef0(param_2);
    return 0;
  }
  if (*(char *)(in_EAX + 0x231) != '\0') {
    *(undefined4 *)(in_EAX + 0xc) = 0x86;
  }
  return 1;
}

