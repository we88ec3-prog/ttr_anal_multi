
int FUN_006f90c0(int param_1,int param_2)

{
  int unaff_ESI;
  
  if ((double)CONCAT44(param_2,param_1) == 0.0) {
    return *(int *)(unaff_ESI + 0x10);
  }
  return ((uint)(param_2 + param_1) % ((1 << (*(byte *)(unaff_ESI + 7) & 0x1f)) - 1U | 1)) * 0x20 +
         *(int *)(unaff_ESI + 0x10);
}

