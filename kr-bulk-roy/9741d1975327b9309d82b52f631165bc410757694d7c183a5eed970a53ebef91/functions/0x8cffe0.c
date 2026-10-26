
char * FUN_008cffe0(uint param_1)

{
  if (0x186 < param_1) {
    return (char *)0x0;
  }
  return ".null" + *(short *)(&DAT_00bd9590 + param_1 * 2);
}

