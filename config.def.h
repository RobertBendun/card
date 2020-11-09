static char const *title = "Example Card";

static Entry const entries[] = {
	{ "", "" }, /* extra space between title and entries */
	{ "Email", "contact@example.com" },
	{ "Website", "example.com" },
	{ "", "" }, /* another separator */
	{ "Pets", "cat, dog" },
	{ "Food", "pizza, ham" }
};

// padding between frame and card content
static unsigned const padding = 3;

// characters used to draw frame
static char const *T[] = { "╔", "═", "╗" };
static char const *M[] = { "║", " ", "║" };
static char const *D[] = { "╚", "═", "╝" };

// flags to toogle visual effects (true or false, 1 or 0)
#define BoldTitle false
#define BoldField true

