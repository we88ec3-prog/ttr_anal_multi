
void FUN_0087e281(void)

{
  undefined4 *puVar1;
  undefined4 *_Memory;
  LONG *Target;
  
  Target = (LONG *)&DAT_00f8c868;
  do {
    _Memory = (undefined4 *)InterlockedExchange(Target,0);
    while (_Memory != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*_Memory;
      __free_locale((_locale_t)_Memory[2]);
      _free(_Memory);
      _Memory = puVar1;
    }
    Target = Target + 1;
  } while ((int)Target < 0xf8c960);
  return;
}

