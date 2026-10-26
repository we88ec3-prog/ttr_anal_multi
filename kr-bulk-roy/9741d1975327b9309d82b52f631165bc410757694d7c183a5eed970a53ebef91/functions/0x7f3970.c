
void FUN_007f3970(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 0x10);
  puVar3 = (undefined4 *)*puVar1;
  do {
    if (puVar3 == puVar1) {
      iVar2 = FUN_0074d700(puVar1,puVar1[1],&param_1);
      puVar3 = puVar1;
LAB_007f39b8:
      if (*(int *)(unaff_EDI + 0x14) != 0x3ffffffe) {
        *(int *)(unaff_EDI + 0x14) = *(int *)(unaff_EDI + 0x14) + 1;
        puVar3[1] = iVar2;
        **(int **)(iVar2 + 4) = iVar2;
        return;
      }
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    if (*(float *)(param_1 + 0x18) < *(float *)(puVar3[2] + 0x18)) {
      iVar2 = FUN_0074d700(puVar3,puVar3[1],&param_1);
      goto LAB_007f39b8;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}

