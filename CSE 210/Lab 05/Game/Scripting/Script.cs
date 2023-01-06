using System.Collections.Generic;


namespace Unit05.Game.Scripting
{
    /// <summary>
    /// <para>A collection of actions.</para>
    /// <para>
    /// The responsibility of a cast is to keep track of a collection of actions. It has methods for 
    /// adding, removing and getting them by a group name.
    /// </para>
    /// </summary>
    public class Script
    {
        private Dictionary<string, Dictionary<string, Action>> actions 
        = new Dictionary<string, Dictionary<string, Action>>();

        /// <summary>
        /// Constructs a new instance of Script.
        /// </summary>
        public Script()
        {
        }

        /// <summary>
        /// Adds the given action to the given group.
        /// </summary>
        /// <param name="group">The group name.</param>
        /// <param name="action">The action to add.</param>
        public void AddAction(string group, string name, Action action)
        {
            if (!actions.ContainsKey(group))
            {
                actions[group] = new Dictionary<string, Action>();
            }

            if (!actions[group].ContainsKey(name))
            {
                actions[group].Add(name, action);
            }
        }

        public Action GetAction(string group, string name)
        {
            Action result = null;
            if (actions.ContainsKey(group))
            {
                if (actions[group].ContainsKey(name))
                {
                    result = actions[group][name];
                }
            }
            return result;
        }

        /// <summary>
        /// Gets the actions in the given group. Returns an empty list if there aren't any.
        /// </summary>
        /// <param name="group">The group name.</param>
        /// <returns>The list of actions.</returns>
        public Action GetActions(string group, string name)
        {
            Action results = null;
            if (actions.ContainsKey(group))
            {
                results = actions[group][name];
                
            }
            return results;
        }
    }
}