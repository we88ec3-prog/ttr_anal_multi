
void FUN_007d4430(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  undefined1 local_88 [132];
  
  uVar2 = FUN_0077ef30();
  uVar2 = FUN_0077ef30(uVar2);
  puVar3 = (undefined4 *)FUN_0077e910(local_88,uVar2);
  uVar2 = puVar3[1];
  uVar1 = puVar3[2];
  *unaff_ESI = *puVar3;
  unaff_ESI[1] = uVar2;
  unaff_ESI[2] = uVar1;
  return;
}

