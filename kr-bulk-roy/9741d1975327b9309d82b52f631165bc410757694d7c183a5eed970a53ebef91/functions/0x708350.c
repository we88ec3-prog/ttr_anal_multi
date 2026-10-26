
undefined4 FUN_00708350(void)

{
  undefined8 *puVar1;
  int iVar2;
  FILE *in_ECX;
  int unaff_ESI;
  undefined8 local_c;
  
  iVar2 = FID_conflict__fscanf(in_ECX,"%lf",&local_c);
  if (iVar2 == 1) {
    puVar1 = *(undefined8 **)(unaff_ESI + 8);
    *puVar1 = local_c;
    *(undefined4 *)(puVar1 + 1) = 3;
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    return 1;
  }
  return 0;
}

