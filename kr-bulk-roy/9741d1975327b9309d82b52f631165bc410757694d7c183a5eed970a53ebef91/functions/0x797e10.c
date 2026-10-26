
void FUN_00797e10(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_EAX;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  undefined1 local_3c [56];
  
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_EAX + 4) + 0x24))(local_3c);
  uVar1 = puVar3[1];
  uVar2 = puVar3[2];
  *unaff_ESI = *puVar3;
  unaff_ESI[1] = uVar1;
  unaff_ESI[2] = uVar2;
  return;
}

