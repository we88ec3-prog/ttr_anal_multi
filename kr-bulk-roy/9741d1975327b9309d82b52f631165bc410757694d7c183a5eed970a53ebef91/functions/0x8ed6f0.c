
void FUN_008ed6f0(ushort *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  
  if (*param_1 < *(ushort *)(in_EAX + 0x74)) {
    iVar3 = (uint)*param_1 * 8;
    (**(code **)(in_EAX + 0x23c))();
    (**(code **)(in_EAX + 0x248))();
    if (*(short *)(in_EAX + 0x15c) == 0) {
      iVar1 = *(int *)(in_EAX + 0x7c);
      iVar2 = *(int *)(in_EAX + 0x78);
      *(undefined4 *)(iVar2 + iVar3) = *(undefined4 *)(iVar1 + iVar3);
      *(undefined4 *)(iVar2 + 4 + iVar3) = *(undefined4 *)(iVar1 + 4 + iVar3);
    }
  }
  else if (*(char *)(in_EAX + 0x231) != '\0') {
    *(undefined4 *)(in_EAX + 0xc) = 0x86;
    return;
  }
  return;
}

