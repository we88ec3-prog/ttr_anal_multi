
undefined4 FUN_008df080(void)

{
  undefined4 *puVar1;
  code *pcVar2;
  int *in_EAX;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = *(undefined4 **)(*(int *)(*in_EAX + 0x290) + 0xb88);
  iVar3 = FUN_008b8f30(*(undefined4 *)(*(int *)(*in_EAX + 0x60) + 4),"pshinter");
  if (((iVar3 != 0) && (puVar1 != (undefined4 *)0x0)) &&
     (pcVar2 = (code *)*puVar1, pcVar2 != (code *)0x0)) {
    uVar4 = (*pcVar2)(iVar3);
    return uVar4;
  }
  return 0;
}

